import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;     // 총 걸린시간.
        int sum = 0;        // 다리 위에 있는 트럭들의 무게 합.
        int truckIdx = 0;       // 트럭의 인덱스.
        Queue<Integer> truckStart = new LinkedList<>();     // 트럭이 출발하는 시점들.
        Queue<Integer> onBridge = new LinkedList<>();       // 다리 위에 있는 트러의 무게들.
        
        while (true) {
            answer++;       // 시간 증가.
            
            // 트럭의 무게가 다리의 무게보다 작으면, 트럭을 다리에 올리기.
            if (sum + truck_weights[truckIdx] <= weight) {
                // 마지막 트럭이 다리에 오르면 종료.
                if (truckIdx == truck_weights.length - 1) {
                    // 마지막 트럭 도착시간 추가.
                    answer += bridge_length;
                    break;
                }
                
                onBridge.add(truck_weights[truckIdx]);
                truckStart.add(answer);     // 트럭이 다리에 오르는 시간 add.
                sum += truck_weights[truckIdx];
                truckIdx++;
            }
            
            // 현재 시간 - 다리 위 제일 앞 트럭 출발시간 == 다리 길이 -> 트럭 도착.
            if (answer - truckStart.peek() == bridge_length) {
                sum -= onBridge.poll();     // poll : 큐의 첫 번째 값을 반환하고 제거, 비어있다면 null.
                truckStart.remove();        // remove : 큐의 첫 번째 값 제거.
            }
        }
        return answer;
    }
}
